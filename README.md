# ROS-Exercise
I wrote this with yhe help of tutorials on [ROS wiki](http://wiki.ros.org/ROS/Tutorials).

I did some practise on my own.
## Authors and Current Version
* Author:
  - [@Cuijie12358](https://github.com/Cuijie12358)<br/>
## Platform
- ROS indigo/kinetic
- ubuntu 14.04/16.04
 
## Structure
* ROS_template

It is used as a template to commit.
* srv

AddTwoInts is the sample on wiki.

DirAndDis is which I wrote to calculate the times "w""a""s""d" is pressed by sending "up""left""down" and "right" in a service.
* src

  * dir_and_dis_client<br/>
  * dir_and_dis_server<br/>
    A service to finish this task.<br/>
  * talker and listener<br/>
    using topic and message to finish this task.<br/>
  * fibonacci_server<br/>
    action tutorial<br/>
  * teleop_wasd<br/>
    Using wasd to control the turtlesim, inspired by [this](http://blog.csdn.net/under_maple/article/details/49430765).  
    Though it cannot be killed by pressing ctrl-c since I got everything in the stream,it performs well :)  
    I had wrote it long time ago but I missed the file so I didn't push this until today(11/1/2018). 
 
## Test
They can be divided by their names.   
```
rosrun testpack teleop_wasd
```
Then just press the key.   
I have to commit that it could be slow to identificate the key at first, but things get quite soomth after a while. What'more, notice that it cannot recognize two keys at a time and that's why you have to close the terminal to kill it.
