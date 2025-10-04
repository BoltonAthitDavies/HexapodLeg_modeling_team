#!/usr/bin/env python3
"""
CyberGear Motor Scanner
Scans CAN bus for all connected CyberGear motors and displays their IDs and status
"""

import can
import time
import sys
from cybergear import CyberGear

def scan_motors(max_id=127, timeout=0.1):
    """
    Scan for CyberGear motors on the CAN bus

    Args:
        max_id: Maximum motor ID to scan (default: 127)
        timeout: Timeout for each motor response in seconds

    Returns:
        List of detected motor IDs
    """
    print("=" * 60)
    print("CyberGear Motor Scanner")
    print("=" * 60)

    # Initialize CAN bus
    try:
        bus = can.Bus(interface="canalystii", channel=0, bitrate=1000000)
        print("✓ CAN bus initialized successfully")
        print(f"  Interface: canalystii")
        print(f"  Channel: 0")
        print(f"  Bitrate: 1000000 bps")
    except Exception as e:
        print(f"✗ Failed to initialize CAN bus: {e}")
        return []

    cg = CyberGear(bus)
    detected_motors = []

    print("\nScanning for motors (ID 1-127)...")
    print("-" * 60)

    for motor_id in range(1, max_id + 1):
        # Print progress every 10 motors
        if motor_id % 10 == 0:
            print(f"Scanning... {motor_id}/{max_id}")

        try:
            # Try to get feedback from motor using type2 command
            result = cg.type2(motor_id, echo=False)

            if result is not None:
                detected_motors.append(motor_id)
                print(f"✓ FOUND Motor ID: {motor_id}")

                # Extract basic info from feedback
                alarm_code = (result[0] >> 16) & 0xff
                fb = result[1]

                # You can add more detailed info extraction here if needed
                print(f"  Alarm Code: {alarm_code}")

        except Exception as e:
            # Motor not responding at this ID
            pass

    print("-" * 60)
    print(f"\nScan Complete!")
    print(f"Found {len(detected_motors)} motor(s): {detected_motors}")
    print("=" * 60)

    # Clean up
    bus.shutdown()

    return detected_motors

def scan_with_feedback(motor_ids):
    """
    Get detailed feedback from detected motors

    Args:
        motor_ids: List of motor IDs to query
    """
    if not motor_ids:
        print("\nNo motors to query.")
        return

    print("\nGetting detailed feedback from detected motors...")
    print("=" * 60)

    try:
        bus = can.Bus(interface="canalystii", channel=0, bitrate=1000000)
        cg = CyberGear(bus)

        for motor_id in motor_ids:
            print(f"\nMotor ID: {motor_id}")
            print("-" * 40)

            # Get motor feedback
            try:
                result = cg.type2(motor_id, echo=False)

                if result is not None:
                    alarm_code = (result[0] >> 16) & 0xff
                    fb = result[1]

                    # Parse feedback values
                    from cybergear import uint_to_float
                    import math

                    position = uint_to_float(fb[0], -4*math.pi, 4*math.pi)
                    velocity = uint_to_float(fb[1], -30, 30)
                    current = uint_to_float(fb[2], -12, 12)

                    print(f"  Position: {position:.4f} rad ({position*180/math.pi:.2f}°)")
                    print(f"  Velocity: {velocity:.4f} rad/s")
                    print(f"  Current:  {current:.4f} A")
                    print(f"  Alarm Code: {alarm_code}")

                    if alarm_code == 0:
                        print(f"  Status: ✓ OK")
                    else:
                        print(f"  Status: ⚠ Alarm Code {alarm_code}")
                else:
                    print(f"  Status: ✗ No response")

            except Exception as e:
                print(f"  Error reading motor: {e}")

        print("=" * 60)
        bus.shutdown()

    except Exception as e:
        print(f"Error: {e}")

def main():
    print("\nStarting motor scan...\n")

    # Scan for motors
    detected = scan_motors(max_id=127, timeout=0.1)

    # Get detailed feedback if motors found
    if detected:
        print("\nPress Enter to get detailed feedback, or Ctrl+C to exit...")
        try:
            input()
            scan_with_feedback(detected)
        except KeyboardInterrupt:
            print("\nExiting...")
    else:
        print("\n⚠ No motors detected!")
        print("\nTroubleshooting:")
        print("  1. Check CAN bus connections")
        print("  2. Verify motor power supply")
        print("  3. Ensure CAN termination resistors are in place")
        print("  4. Check CANalyst-II USB connection")
        print("  5. Verify CAN bitrate matches motor configuration (1Mbps)")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\nScan interrupted by user.")
        sys.exit(0)
    except Exception as e:
        print(f"\nFatal error: {e}")
        sys.exit(1)
