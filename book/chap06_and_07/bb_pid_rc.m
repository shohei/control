%% bb_pid_rc.m

%% Initialize & load data
close all
clear all
load sim_param

%% サーボ 1度 あたりのアームの傾き
% RCサーボの場合
K_theta_rc = (pi/180)*(1.5/11.5); % [rad/deg]

%% ビーム傾き角 [rad] -> ボール位置 [cm] までの 1/s^2 のゲイン
K_b = (3/5*9.8)*100;

Pb  = K_b/s^2;
Pbd = c2d(Pb,ts,'zoh');
[numbd,denbd] = tfdata(Pbd,'v');

%% PIDパラメータ for Ball位置制御
omega_n = 1.5;
zeta    = 0.6;
alpha   = 0.5;

p1 = (-zeta + j*sqrt(1-zeta^2))*omega_n;
p2 = (-zeta - j*sqrt(1-zeta^2))*omega_n;
p3 = -alpha;

kp  =  (p1*p2 + p2*p3 + p3*p1)/K_b;
ki  = -p1*p2*p3/K_b;
kd  = -(p1+p2+p3)/K_b;
% kff = 0;
kff = ki/alpha;

disp('>>> PID parameters for Ball and Beam <<<')
fprintf('kp  = %f\n',kp);
fprintf('ki  = %f\n',ki);
fprintf('kd  = %f\n',kd);
fprintf('kff = %f\n',kff);

%% Reference for ball position
r1 = 20-5;
r2 = 20+5;

%% LPFカットオフ周波数
wf = 2*pi*2;

%% LPF for ball position sensor
Fc = wf^2/(s^2+2*0.7*wf*s+wf^2);
Fd = c2d(Fc,ts,'tustin');
[numlpf,denlpf] = tfdata(Fd,'v');

%% Open simulink model
open_system('bb_pid_rc_sl');
open_system('bb_pid_rc_sl/Ref angle')
open_system('bb_pid_rc_sl/Ball position and reference')

%% EOF of bb_pid_rc.m