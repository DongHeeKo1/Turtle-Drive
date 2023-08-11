#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    // "/published_topic" 토픽을 publish
    pub_ = n_.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

    // "/subscribed_topic" 토픽을 subscribe
    sub_ = n_.subscribe("joy", 1, &SubscribeAndPublish::callback, this);
  }
 
  void callback(const sensor_msgs::Joy& abc)
  {
  
  geometry_msgs::Twist T ;

  T.linear.x = (abc.axes[2]) ;
  T.angular.z = (abc.axes[0]) ;
  
    
    
    
    // 'callback' 함수 input을 통해 생성된 output을 퍼블리쉬 한다
    pub_.publish(T);
  }  

private:    
  ros::NodeHandle n_;       // NodeHandle 선언
  ros::Publisher pub_;      // Publisher 선언
  ros::Subscriber sub_;     // Subscriber 선언

};   // 'SubscribeAndPublish' class 종료

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "Turtle");

  // 모든 것을 처리 할 SubscribeAndPublish 클래스 개체 'SAPObject' 생성
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
