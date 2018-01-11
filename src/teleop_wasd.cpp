#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <geometry_msgs/Twist.h>

int kbhit(void);
char getch(void);
int main(int argc,char **argv)
{
	ros::init(argc,argv,"teleop_wasd");
	ros::NodeHandle com;
	ros::Publisher chatter_pub = com.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
	ros::Rate loop_rate(10);
	geometry_msgs::Twist msg;
	char temp;
	while(ros::ok())
	{
		while(kbhit())
		{
			temp = getch();
			switch (temp)
			{
				case 'w':
        msg.linear.x=1;break;
				case 'a':
        msg.angular.z= 1;break;
				case 's':
        msg.linear.x=-1;break;
				case 'd':
        msg.angular.z= -1;break;
				default:break;
			}
			chatter_pub.publish(msg);
			ros::spinOnce();
			loop_rate.sleep();
      msg.linear.x=0;
      msg.angular.z=0; 
		}
	}
	return 0;
}

int kbhit(void)

{

    struct termios oldt, newt;

    int ch;

    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);

    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)

    {

        ungetc(ch, stdin);

        return 1;

    }

    return 0;

}

char getch()
{
	char buf = 0;
	struct termios old = {0};
	if(tcgetattr(0,&old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if(tcsetattr(0,TCSANOW,&old) < 0)
		perror("tcsetattr ICANON");
	if(read(0,&buf,1) < 0)
		perror("read()");
	old.c_lflag |= ~ICANON;
	old.c_lflag |= ~ECHO;
	if(tcsetattr(0,TCSADRAIN,&old) < 0)
		perror("tcsetattr ~ICANON");
	return (buf);
}
