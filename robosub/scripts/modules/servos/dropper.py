import rospy
from robosub.msg import Dropper
from std_msgs.msg import Int8
#from modules.main.status import log

# def close_both_gates(self):
#     print 'close both gates'

# def open_both_gates(self):
#     print 'open both gates'

# def drop_one_ball(self):
#     print 'drop one ball'

""" Controls dropper"""

DROP_OPTIONS = {
    0: 'CLOSE BOTH GATES',
    1: 'OPEN BOTH GATES',
    2: 'DROP ONE BALL'
}

dropper = Dropper()
pub = rospy.Publisher('dropper', Dropper, queue_size=100)
pubLed = rospy.Publisher('led', Int8, queue_size=1)

def drop_control(state):
    """
    Changes dropper state
    """
    state = int(state)
    if state in DROP_OPTIONS:
        dropper.state = state
        pub.publish(dropper)
        pubLed.publish(18)
        print(DROP_OPTIONS[state])
