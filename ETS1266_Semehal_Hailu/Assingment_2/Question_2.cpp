#include <iostream>
using namespace std;
int main (){
go:
float test,quiz,project,assignment,final_exam,sum=0;
            cout<<"enter your test score out of 15 please :"<<endl;
            cin>>test;
                    if(test<0|| test>15||cin.fail()){
                            cout<<"invalid input please enter "<<endl;
                            goto go;
                    }
                    go1:
            cout<<"enter your quiz score out of 5 please :"<<endl;
            cin>>quiz;
                    if(quiz<0||quiz>5||cin.fail()){    
                        cout<<"invalid input please enter "<<endl;
                        goto go1;
                    }
                    go2:
            cout<<"enter your project score out of 20 please :"<<endl;
            cin>>project;
                    if(project<0||project>20||cin.fail()){
                        cout<<"invalid input please enter "<<endl;
                        goto go2;
                    }
                    go3:
            cout<<"enter your assignment score out of 10 please :"<<endl;
            cin>>assignment;
                    if(assignment<0||assignment>10||cin.fail()){
                        cout<<"invalid input please enter "<<endl;
                        goto go3;
                    }
                    go4:
            cout<<"enter your final exam score out of 50 please :"<<endl;
            cin>>final_exam;
                    if(final_exam<0||final_exam>50||cin.fail()){
                        cout<<"invalid input please enter "<<endl;
                        goto go4;
                    }
    sum=test+quiz+project+assignment+final_exam;

       if(sum>=90){
          cout<<"For the total score "<<sum<<" the grade letter is A+ "<<endl;
      }
      else if(sum>=80){
          cout<<"For the total score "<<sum<<" the grade letter is A "<<endl;
      }
      else if(sum>=75){
          cout<<"For the total score "<<sum<<" the grade letter is B+ "<<endl;
      }
      else if (sum>=60){
          cout<<"For the total score "<<sum<<" the grade letter is B "<<endl;
      }
      else if(sum>=55){
          cout<<"For the total score "<<sum<<" the grade letter is C+ "<<endl;
      }
      else if(sum>=45){
          cout<<"For the total score "<<sum<<" the grade letter is C "<<endl;
      }
      else if(sum>=30){
          cout<<"For the total score "<<sum<<" the grade letter is D "<<endl;
      }
      else{
          cout<<"For the total score "<<sum<<" the grade letter is F "<<endl;
      }

    return 0;
}
