#include <iostream>
using namespace std;
int main(){
    cout<<"           AASSESSMENT LISTS"<<endl;
    float test,quiz, project, assignment, final;
    cout<<"please enter your test result out of 15"<<endl;
    cin>>test;  cout<<"\n";
    cout<<"please enter your quiz result out of 5"<<endl;
    cin>>quiz;  cout<<"\n";
    cout<<"please enter your project result out of 20"<<endl;
    cin>>project;  cout<<"\n";
    cout<<"please enter your assignment result out of 10"<<endl;
    cin>>assignment;  cout<<"\n";
    cout<<"please enter your final result out of 50"<<endl;
    cin>>final;  cout<<"\n";
    float sum;
    sum=test+quiz+project+assignment+final;
    if(sum>=90){
        cout<<"you got A+ Excellent!!"<<endl;
    } else if(sum<90&&sum>=80){
        cout<<"you got A Very Good"<<endl;
    } else if(sum<80&&sum>=75){
        cout<<"you got B+  Good"<<endl;
    }else if(sum<75&&sum>=60){
        cout<<"you got B study hard!! "<<endl;
    } else if(sum<60&&sum>=55){
        cout<<"you got C+ study hard!! "<<endl;
    }else if(sum<55&&sum>=45){
        cout<<"you got C study hard!"<<endl;
    }else if(sum<45&&sum>=30){
        cout<<"you got D study hard!"<<endl;
    }else if(sum<30){
        cout<<"oops!! you got F study hard "<<endl;
    }
    
    
    
    
    
    
    return 0;
}
