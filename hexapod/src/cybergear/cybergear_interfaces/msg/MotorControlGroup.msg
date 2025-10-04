# MotorGroupControl.msg
# ใช้สำหรับส่งคำสั่งควบคุมมอเตอร์หลายตัวพร้อมกัน
# รวม header สำหรับข้อมูลเวลาและการ sync คำสั่งด้วย

std_msgs/Header header
MotorControl[] motor_controls