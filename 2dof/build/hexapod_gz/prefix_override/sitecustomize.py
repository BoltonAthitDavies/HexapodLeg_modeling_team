import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ambushee/HexapodLeg_modeling_team/2dof/install/hexapod_gz'
