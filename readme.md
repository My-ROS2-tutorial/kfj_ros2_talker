## Introduction

The talker sends "Hello ROS2 number" periodically.

## Usage

```.sh
ament build --only-packages kfj_ros2_talker
. install/local_setup.sh
run kfj_ros2_talker talker1
```

Output

```
$ ros2 run kfj_ros2_talker talker1
Publishing: 'Hello ROS2 0'
Publishing: 'Hello ROS2 1'
Publishing: 'Hello ROS2 2'
Publishing: 'Hello ROS2 3'
```
