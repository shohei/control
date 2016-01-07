close all;
clear all;

load modeldata;

p1=input('p1= ');
p2=p1;
Kp=-1*((p1+p2)*T+1)/K;
Ki=p1*p2*T/K;

disp('>>> PI parameters <<<');
fprintf('Kp = %f\n',Kp);
fprintf('Ki = %f\n',Ki);

open_system('velo_pi');
open_system('velo_pi/Scope');

ts=1/50;
set_param('velo_pi','SimulationCommand','start');
