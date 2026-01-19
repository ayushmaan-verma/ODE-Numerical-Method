/*
    ##################### HOW TO USE THE PROGRAM #####################

    We can input our desirable First-order differential eqn in the diff_eqn() function.
    The input should be made in following way:-
    
        Let the diff eqn be in this form dy/dx = f(x,y);
        Modify this part accordingly : return f(x,y);

    For e.g.
        Here the Differential Eqn being used is: dy/dx = 2xy 
        Whose solution is actaully: y = e^(x^2) + c

    You can improve the accuracy of output, by decreasing the Step Size.
    To do it you have to go to "approx()" function and decrease the value of "step_size" variable.

    The function is: *approx(method,x,x0,y0)*.

        1. method = An integer(1,2 or 3) which sets different numerical techniques.
                (NOTE: Greater the value, more will be the accuracy.)
                    Use 1 for Euler Method.
                    Use 2 for Modified Euler Method (Heun's Method).
                    Use 3 for Runge-Kutta Method (RK4).
            Fun Fact: You can increase step size for RK4 and still beat Euler accuracy.

        2. x = Value of 'x' at which we want to get the value of function i.e. y(x).

        3. (x0,y0) = Any point which satisfies the curve.

    ######################## THANKS A LOT <3 #########################
*/

#include<iostream>
using namespace std;

double diff_eqn(double x, double y){
    return 2*x*y ;
}

double euler(double step_size, double step, double x0, double y0){
    if(step == 0){
        return y0;
    }
    return euler(step_size, step - 1,x0 + step_size,y0 + step_size*diff_eqn(x0,y0));
}

double modified_euler(double step_size, double step, double x0, double y0){
    if(step == 0){
        return y0;
    }
    double k1 = step_size*diff_eqn(x0,y0);
    double k2 = step_size*diff_eqn(x0 + step_size,y0 + k1);
    return modified_euler(step_size, step - 1,x0 + step_size,y0 + (k1+k2)/2);
}

double rk4(double step_size, double step, double x0, double y0){
    if(step == 0){
        return y0;
    }
    double k1 = step_size*diff_eqn(x0,y0);
    double k2 = step_size*diff_eqn(x0 + step_size/2, y0 + k1/2);
    double k3 = step_size*diff_eqn(x0 + step_size/2,y0 + k2/2);
    double k4 = step_size*diff_eqn(x0 + step_size, y0 + k3);
    return rk4(step_size, step - 1,x0 + step_size,y0 + (k1+(2*k2)+(2*k3)+k4)/6);
}

double approx(int method, double x, double x0, double y0){

    double step_size = 0.00001;
    int step = (x-x0)/step_size;

    switch (method){
        case 1:
            return euler(step_size,step,x0,y0);
            break;
        case 2:
            return modified_euler(step_size,step,x0,y0);
            break;
        case 3:
            return rk4(step_size,step,x0,y0);
            break;
        default:
            return 0;
    }
}

int main(){
    cout << "EULER = " << approx(1,1,0,1) << endl;
    cout << "MODIFIED EULER = " << approx(2,1,0,1) << endl;
    cout << "RK4 = " << approx(3,1,0,1) << endl;
}