import numpy as np
from pydrake.trajectories import PiecewisePolynomial
from statemachine import StateMachine, State

class VoltaStateMachine(StateMachine):
    # Define states
    disable_controller = State('DisableController', initial=True)
    hold_position = State('HoldPosition')
    home = State('Home')
    walking = State('Walking')
    
    # Define transitions based on operation_command values
    # operation_command: -1=disable, 0=home, 1=walking, 2=hold_position
    
    # From disable_controller
    to_home_from_disable = disable_controller.to(home)
    to_walk_from_disable = disable_controller.to(walking)
    to_hold_from_disable = disable_controller.to(hold_position)
    stay_disabled = disable_controller.to(disable_controller)
    
    # From hold_position
    to_disable_from_hold = hold_position.to(disable_controller)
    to_home_from_hold = hold_position.to(home)
    to_walk_from_hold = hold_position.to(walking)
    stay_holding = hold_position.to(hold_position)
    
    # From home
    to_disable_from_home = home.to(disable_controller)
    to_walk_from_home = home.to(walking)
    to_hold_from_home = home.to(hold_position)
    stay_home = home.to(home)
    
    # From walking
    to_disable_from_walk = walking.to(disable_controller)
    to_home_from_walk = walking.to(home)
    to_hold_from_walk = walking.to(hold_position)
    stay_walk = walking.to(walking)

    def __init__(self,gait_planner):
        super().__init__()
        self.GaitPlanner = gait_planner
        self.GaitPlanner.CalcTrajectory()
        self.q_init_L  = self.GaitPlanner.L_leg_init_joints_positions.T
        self.q_init_R  = self.GaitPlanner.R_leg_init_joints_positions.T
        self.qd_init_L = self.GaitPlanner.L_leg_init_joints_velocities.T
        self.qd_init_R = self.GaitPlanner.R_leg_init_joints_velocities.T

        self.sw_leg_q = self.GaitPlanner.L_leg_joints_positions.T
        self.st_leg_q = self.GaitPlanner.R_leg_joints_positions.T
        self.sw_leg_qd = self.GaitPlanner.L_leg_joints_velocities.T
        self.st_leg_qd = self.GaitPlanner.R_leg_joints_velocities.T
        self.dt = 0.01
        self.ind = 0
        self.L_leg_q = self.q_init_L[:,self.ind]
        self.R_leg_q = self.q_init_R[:,self.ind]

        self.L_leg_qd = self.qd_init_L[:,self.ind]
        self.R_leg_qd= self.qd_init_R[:,self.ind]

        self.walking_state = "Init"
        # Robot state variables
        self.controller_enable = False
        self.operation_command = -1
        self.num_motors = 12
        self.current_joints_position = np.zeros(self.num_motors)  # 6 DOF per leg
        self.desired_joints_position = np.zeros(self.num_motors)
        self.desired_joints_velocity = np.zeros(self.num_motors)
        self.hold_joints_position = np.zeros(self.num_motors)
        self.action_msg = ""

    def SetOperationCommand(self, command):
        """Set walk command and trigger appropriate transition"""
        self.operation_command = command
        self._ProcessOperationCommand()
    
    def _ProcessOperationCommand(self):
        """Process walk command and trigger appropriate state transition"""
        if self.operation_command == -1:
            self._TransitionToDisable()
        elif self.operation_command == 0:
            self._TransitionToHome()
        elif self.operation_command == 1:
            self._TransitionToWalk()
        elif self.operation_command == 2:
            self._TransitionToHold()

    def _TransitionToDisable(self):
        """Transition to disable controller state"""
        if self.current_state == self.hold_position:
            self.to_disable_from_hold()
        elif self.current_state == self.home:
            self.to_disable_from_home()
        elif self.current_state == self.walking:
            self.to_disable_from_walk()
        else:
            self.stay_disabled()
    
    def _TransitionToHome(self):
        """Transition to home state"""
        if self.current_state == self.disable_controller:
            self.to_home_from_disable()
        elif self.current_state == self.hold_position:
            self.to_home_from_hold()
        elif self.current_state == self.walking:
            self.to_home_from_walk()
        else:
            self.stay_home()
    
    def _TransitionToWalk(self):
        """Transition to walk execution state"""
        if self.current_state == self.disable_controller:
            self.to_walk_from_disable()
        elif self.current_state == self.hold_position:
            self.to_walk_from_hold()
        elif self.current_state == self.home:
            self.to_walk_from_home()
        else:
            self.stay_walk()
    
    def _TransitionToHold(self):
        """Transition to hold position state"""
        if self.current_state == self.disable_controller:
            self.to_hold_from_disable()
        elif self.current_state == self.home:
            self.to_hold_from_home()
        elif self.current_state == self.walking:
            self.to_hold_from_walk()
        else:
            self.stay_holding()
        
        # State entry actions using decorator syntax
    
    @disable_controller.enter
    def enter_disable_controller(self):
        """Actions when entering disable_controller state"""
        self.action_msg = "Entering disable_controller state"
        print(self.action_msg)
        self.controller_enable = False

    @hold_position.enter
    def enter_hold_position(self):
        """Actions when entering hold_position state"""
        self.action_msg = f"Entering hold_position state at position: {self.current_joints_position}"
        print(self.action_msg)
        self.controller_enable = True
        self.hold_joints_position = self.current_joints_position.copy()
        self.desired_joints_position = self.hold_joints_position.copy()
        self.desired_joints_velocity = np.zeros(self.num_motors)
    
    @walking.enter
    def enter_walking(self):
        """Actions when entering walking state"""
        self.action_msg = "Entering walking state"
        print(self.action_msg)
        self.GaitPlanner.UpdateInitialTrajectory(initial_joints_position=self.current_joints_position)
        self.q_init_L  = self.GaitPlanner.L_leg_init_joints_positions.T
        self.q_init_R  = self.GaitPlanner.R_leg_init_joints_positions.T
        self.qd_init_L = self.GaitPlanner.L_leg_init_joints_velocities.T
        self.qd_init_R = self.GaitPlanner.R_leg_init_joints_velocities.T
        self.desired_joints_position = self.current_joints_position.copy()
        self.desired_joints_velocity = np.zeros(self.num_motors)
        self.controller_enable = True
        self.walking_state = "Init"
        self.ind = 0
    
    def UpdateWalkingState(self):
        if self.current_state == self.walking:
            match self.walking_state:
                case "Init":
                    if self.ind <= self.q_init_L.shape[1] - 1:
                        self.L_leg_q = self.q_init_L[:,self.ind]
                        self.R_leg_q = self.q_init_R[:,self.ind]

                        self.L_leg_qd = self.qd_init_L[:,self.ind]
                        self.R_leg_qd = self.qd_init_R[:,self.ind]
                    else:
                        pass
                        # self.walking_state = "Walking"
                        # self.ind = 0
                    self.ind += 1
                        
                case "Walking":
                    if self.ind < self.sw_leg_q.shape[1]-1:
                        self.ind += 1
                        self.L_leg_q = self.sw_leg_q[:,self.ind]
                        self.R_leg_q = self.st_leg_q[:,self.ind]
                        self.L_leg_qd = self.sw_leg_qd[:,self.ind]
                        self.R_leg_qd= self.st_leg_qd[:,self.ind]
                    else:
                        self.ind = 0
                        self.L_leg_q = self.st_leg_q[:,self.ind]
                        self.R_leg_q = self.sw_leg_q[:,self.ind]
                        self.L_leg_qd = self.st_leg_qd[:,self.ind]
                        self.R_leg_qd= self.sw_leg_qd[:,self.ind]
            q = np.concatenate((np.array([self.L_leg_q]), np.array([self.R_leg_q])),axis=1)
            qd = np.concatenate((np.array([self.L_leg_qd]), np.array([self.R_leg_qd])),axis=1)
            self.desired_joints_position = q[0]
            self.desired_joints_velocity = qd[0]
            

    def GetControllerEnabledCommand(self):
        return int(self.controller_enable)
    
    def GetDesiredJointsPosition(self):
        return self.desired_joints_position
    
    def GetDesiredJointsVelocity(self):
        return self.desired_joints_velocity
    
    def GetCurrentStateName(self):
        return self.current_state.id
    
    def UpdateCurrentJointsPosition(self, q):
        self.current_joints_position = q