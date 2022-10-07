#include <cmath>
#include<iostream>
using namespace std;

int main()
{
  int x, y;
    double m, result;
    cout<<"enter x";
    cin>>x;
    cout<<"enter y";
    cin>>y;
    m=y/x;
    
  
    if (x>0){
        result = atan(m)*180/3.1415;
        cout <<result<<endl;
  }
  else if (x<0){
    result = (atan(m)*180/3.1415)+180;
        cout <<result<< endl;
    
  }
  else if(x==0){
    if (y>0){
      result=90;
        cout<<result<<endl; 
    }
    else if (y<0){
      result=270
        cout<<result<<endl; 
    }
  }
  
  //Right
  if (-30<=result<=30){
    cout<<"LEFT"<<endl;
  }
  //NE
  else if(30<result<60){
    cout<<"NE"<<endl
  }
  
  //Front
  else if(60<=result<=120){
    cout<<"Front"<<endl;
  }
  //NW
  else if(120<result<150){
    cout<<"NW"<<endl;
  }
  //Left
  else if(150<=result<=210){
    cout<<"Left"<<endl;
  }
  //SW
  else if(210<result<240){
    cout<<"SW"<<endl;
  }
  //SE
  else if(-60<result<-30){
    cout<<"SE"<<endl;
  }
  
  //Back
  else if(-90<=result<=-60){
    cout<<"Back"<<endl;
  }
  else if(240<=result<=270){
    cout<<"Back"<<endl;
  }
  
    return 0;
}
