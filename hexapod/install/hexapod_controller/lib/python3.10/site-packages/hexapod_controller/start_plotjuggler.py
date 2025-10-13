#!/usr/bin/env python3
import os
import subprocess

import rclpy
from rclpy.node import Node


class StartPlotJuggler(Node):
    def __init__(self):
        super().__init__('start_plotjuggler')
        self.declare_parameter('layout_path', '')
        self.timer = self.create_timer(1.0, self._launch)
        self.once = False

    def _launch(self):
        if self.once:
            return
        self.once = True
        layout = self.get_parameter('layout_path').get_parameter_value().string_value
        cmd = ['plotjuggler']
        if layout and os.path.exists(layout):
            cmd += ['--layout', layout]
        self.get_logger().info(f"Launching PlotJuggler: {' '.join(cmd)}")
        try:
            subprocess.Popen(cmd)
        except Exception as e:
            self.get_logger().error(f"Failed to start PlotJuggler: {e}")


def main():
    rclpy.init()
    node = StartPlotJuggler()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
