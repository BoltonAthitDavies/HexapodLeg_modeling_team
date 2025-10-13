class PDController:
    def __init__(self, Kp, Kd):
        """
        Initialize PD controller with proportional and derivative gains.
        Kp: proportional gain for position error
        Kd: derivative gain for velocity error
        """
        self.Kp = Kp
        self.Kd = Kd

    def compute_torque(self, set_angle, current_angle, set_speed, current_speed, t_ref=0.0):
        """
        Compute desired torque based on the PD control diagram.

        Parameters:
        -----------
        set_angle : float
            Target angle (reference position)
        current_angle : float
            Measured angle (feedback)
        set_speed : float
            Target angular velocity (reference)
        current_speed : float
            Measured angular velocity (feedback)
        t_ref : float
            External torque feedforward (optional)

        Returns:
        --------
        desired_torque : float
            Control output torque
        """

        # Compute angle and speed errors
        angle_error = set_angle - current_angle
        speed_error = set_speed - current_speed

        # Compute torque contributions
        torque_p = self.Kp * angle_error      # Proportional term
        torque_d = self.Kd * speed_error      # Derivative term

        # Combine torques + feedforward
        desired_torque = torque_p + torque_d + t_ref
        return desired_torque


# Example usage
if __name__ == "__main__":
    controller = PDController(Kp=2.0, Kd=0.5)

    set_angle = 30.0       # degrees or radians (consistent units)
    current_angle = 25.0
    set_speed = 5.0        # rad/s
    current_speed = 3.0
    t_ref = 0.1            # optional torque bias

    torque = controller.compute_torque(set_angle, current_angle, set_speed, current_speed, t_ref)
    print(f"Desired Torque: {torque:.3f}")
