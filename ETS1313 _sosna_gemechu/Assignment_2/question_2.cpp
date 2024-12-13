#include <iostream>
using namespace std;
int main(){
    cout<<"           AASSESSMENT LISTS FOR STUDENT OUT OF 100%"<<endl;
    cout<<"\n";
    float test,quiz, project, assignment, final;
    go :
    cout<<"please enter your test result out of 15"<<endl;
    cin>>test;  cout<<"\n";
    if(test<0||test>15||cin.fail()){
         cout<<"plesase enter valid input"<<endl;
        goto go;
    }
    go1 :
    cout<<"please enter your quiz result out of 5"<<endl;
    cin>>quiz;  cout<<"\n";
    if(quiz<0||quiz>5||cin.fail()){
         cout<<"plesase enter valid input"<<endl;
        goto go1;
    }
    go2 :
    cout<<"please enter your project result out of 20"<<endl;
    cin>>project;  cout<<"\n";
    if(project<0||project>20||cin.fail()){
         cout<<"plesase enter valid input"<<endl;
        goto go2;
    }
    go3 :
    cout<<"please enter your assignment result out of 10"<<endl;
    cin>>assignment;  cout<<"\n";
    if(assignment<0||assignment>10||cin.fail()){
         cout<<"plesase enter valid input"<<endl;
        goto go3;
    }
    go4 :
    cout<<"please enter your final result out of 50"<<endl;
    cin>>final;  cout<<"\n";
    if(final<0||final>50||cin.fail()){
         cout<<"plesase enter valid input"<<endl;
        goto go4;
    }
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
