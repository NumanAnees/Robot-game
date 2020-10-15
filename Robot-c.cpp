#include<iostream>
#include<math.h>
using namespace std;
class Robot{
public:

    void setRobotName(string n)
    {
         name = n;

    }
    string getRobotName() const
    {
    return name;
    }
    void setLocationX(int v)
    {
        row = v;

    }
    int getLocationX() const
    {
        return row;
    }
    void setLocationY(int v)
    {
        col = v;

    }
    int getLocationY() const
    {
        return col;

    }
    void setDirection (char d)
    {
         direction = d;

    }
    char getDirection() const
    {
        return direction;
    }

    void setRobot(string n, int cx, int cy, char d){
        name = n;
        row = cx;
        col = cy;
        direction = d;

    }

    bool canStep()
    {
        true;

    }
    void takeStep()
    {
        if (direction=='u'){
            col = 1+col;
        }
        else if(direction=='d'){

            col = col-1;
        }
        else if(direction=='l'){

            row = row-1;
        }
        else if(direction=='r'){

            row = 1+row;
        }

    }
    void turnLeft ()
    {
        if(direction=='u'){
            direction = 'l';
        }
        else if (direction == 'r'){

            direction= 'u';
        }
        else if(direction == 'd'){
            direction = 'r';
        }
        else if( direction == 'l'){

            direction = 'd';
        }

    }
    void turnRight ()
    {
        if(direction=='u'){
            direction = 'r';
        }
        else if (direction == 'r'){

            direction= 'd';
        }
        else if(direction == 'd'){
            direction = 'l';
        }
        else if( direction == 'l'){

            direction = 'u';
        }


    }
    void turnBackword ()
    {
    if(direction=='u'){
            direction = 'd';
        }
        else if (direction == 'r'){

            direction= 'l';
        }
        else if(direction == 'd'){
            direction = 'u';
        }
        else if( direction == 'l'){

            direction = 'r';
        }

    }
    void display() const{

        cout<<getRobotName()<<" is at ("<<getLocationX()<<","<<getLocationY()<<") towards "<<getDirection()<<endl;
    }
private:
string name;
    int row, col;
    char direction; // u(up), d(down), l(left), r(right) on Cartesian plane
};
void func(Robot &c){
    string name;
    int x,y;
    char d;
    cout<<"Enter the Robot name :";
    cin>>name;
    c.setRobotName(name);
    d:
    cout<<endl<<"Enter the X-Location :";
    cin>>x;
    if(x>=100){
        cout<<"Enter a valid number between 0-99";
        goto d;
    }
    c.setLocationX(x);
    e:
    cout<<endl<<"Enter the Y-Location :";
    cin>>y;
    if(y>=100){
        cout<<"Enter a valid number between 0-99";
        goto e;
    }
    c.setLocationY(y);
    cout<<endl<<"Enter the direction :";
    cin>>d;
    c.setDirection(d);
    cout<<endl<<endl<<"***********************"<<endl;
}
void func2(Robot &R,Robot &T){
       int target =1+ T.getLocationX();
            int target2 =1+T.getLocationY()+1;
        if(R.getLocationX()>=target&&R.getLocationY()>=target2){
            if(R.getDirection() == 'u'){
                R.turnBackword();
                goto numan;
            }
            else if(R.getDirection()=='l'){
                R.turnLeft();
                goto numan;

            }
            else if(R.getDirection()=='r'){
                R.turnRight();
                goto numan;

            }
            else if (R.getDirection()=='d'){
                    numan:
                    for (int i = R.getLocationY();i>=target2;i--){
                        R.takeStep();
                        R.display();
                    }
            }
            R.turnRight();
            for(int i =R.getLocationX();i>target;i--){
                R.takeStep();
                R.display();
            }
        }
    if(R.getLocationX()>=target&&R.getLocationY()<=T.getLocationY()-1){
            if(R.getDirection() == 'u'){
                nomi:
                    for (int i = R.getLocationY();i<T.getLocationY()-1;i++){
                        R.takeStep();
                        R.display();
                    }

            }
            else if(R.getDirection()=='l'){
                R.turnRight();
                goto nomi;

            }
            else if(R.getDirection()=='r'){
                R.turnLeft();
                goto nomi;

            }
            else if (R.getDirection()=='d'){
                    R.turnBackword();
                    goto nomi;
            }
            R.turnLeft();
            for(int i = R.getLocationX();i>T.getLocationX()+1;i--){
                R.takeStep();
                R.display();
            }
        }
        if(R.getLocationX()<=T.getLocationX()-1 && R.getLocationY()<=T.getLocationY()-1){
            if(R.getDirection() == 'u'){
                nomi2:
                    for (int i = R.getLocationY();i<T.getLocationY()-1;i++){
                        R.takeStep();
                        R.display();
                    }

            }
            else if(R.getDirection()=='l'){
                R.turnRight();
                goto nomi2;

            }
            else if(R.getDirection()=='r'){
                R.turnLeft();
                goto nomi2;

            }
            else if (R.getDirection()=='d'){
                    R.turnBackword();
                    goto nomi2;
            }
            R.turnRight();
            for(int i =R.getLocationX();i<T.getLocationX()-1;i++){
                R.takeStep();
                R.display();
            }
        }
 if(R.getLocationX()<=T.getLocationX()-1&&R.getLocationY()>=target2){
            if(R.getDirection() == 'u'){
                R.turnBackword();
                goto numan1;
            }
            else if(R.getDirection()=='l'){
                R.turnLeft();
                goto numan1;

            }
            else if(R.getDirection()=='r'){
                R.turnRight();
                goto numan1;

            }
            else if (R.getDirection()=='d'){
                    numan1:
                    for (int i = R.getLocationY();i>=target2;i--){
                        R.takeStep();
                        R.display();
                    }
            }
            R.turnLeft();
            for(int i =R.getLocationX();i<T.getLocationX()-1;i++){
                R.takeStep();
                R.display();
            }
        }
        if(R.getLocationX()== T.getLocationX()&& R.getLocationY()> T.getLocationY()){
            if(R.getDirection() == 'u'){
                R.turnBackword();
                goto numan2;
            }
            else if(R.getDirection()=='l'){
                R.turnLeft();
                goto numan2;

            }
            else if(R.getDirection()=='r'){
                R.turnRight();
                goto numan2;

            }
            else if (R.getDirection()=='d'){
                    numan2:
                    for (int i = R.getLocationY();i>=target2;i--){
                        R.takeStep();
                        R.display();
                    }
            }
        }
    if(R.getLocationX()== T.getLocationX()&& R.getLocationY()< T.getLocationY()){
        if(R.getDirection() == 'u'){
                nomi3:
                    for (int i = R.getLocationY();i<T.getLocationY()-1;i++){
                        R.takeStep();
                        R.display();
                    }

            }
            else if(R.getDirection()=='l'){
                R.turnRight();
                goto nomi3;

            }
            else if(R.getDirection()=='r'){
                R.turnLeft();
                goto nomi3;

            }
            else if (R.getDirection()=='d'){
                    R.turnBackword();
                    goto nomi3;
            }

    }
    if(R.getLocationY()==T.getLocationY()&&R.getLocationX() > T.getLocationX() ){
        if(R.getDirection() == 'u'){
                R.turnLeft();
                goto numan21;
            }
            else if(R.getDirection()=='l'){
                numan21:
                    for (int i = R.getLocationX();i>T.getLocationX()+1;i--){
                        R.takeStep();
                        R.display();
                    }

            }
            else if(R.getDirection()=='r'){
                R.turnBackword();
                goto numan21;

            }
            else if (R.getDirection()=='d'){
                R.turnRight();
                goto numan21;
            }

    }
    if(R.getLocationY()== T.getLocationY()&&R.getLocationX() < T.getLocationX() ){
       if(R.getDirection() == 'u'){
                R.turnRight();
                goto numan212;
            }
            else if(R.getDirection()=='l'){
                R.turnBackword();
                goto numan212;

            }
            else if(R.getDirection()=='r'){

                numan212:
                    for (int i = R.getLocationX();i<T.getLocationX()-1;i++){
                        R.takeStep();
                        R.display();
                    }

            }
            else if (R.getDirection()=='d'){
                R.turnLeft();
                goto numan212;
            }


    }
    cout<<endl<<"New location of "<<R.getRobotName()<<" :";
          R.display();
    cout<<endl;
}

int main(){
    Robot R;
    func(R);
    Robot S;
    func(S);
    Robot T;
    func(T);
    Robot Q;
    func(Q);
    Robot P;
    func(P);
    Robot Z;
    func(Z);
    cout<<endl<<"Location of Robots :"<<endl;
    R.display();
    S.display();
    T.display();
    Q.display();
    P.display();
    Z.display();

    cout<<endl<<"************************"<<endl;
    cout<<"Location After going Towards Robot T"<<endl;
     func2(R,T);
     func2(S,T);
     func2(Q,T);
     func2(P,T);
     func2(Z,T);

return 0;
}
