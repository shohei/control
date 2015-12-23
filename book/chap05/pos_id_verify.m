%% pos_id_verify.m

%% Set identified parameters
K = 365
T = 0.32

%% Discrete-time plant model
P  = K/(T*s^2 + s);
Pd = c2d(P,ts,'zoh');
[numpd,denpd] = tfdata(Pd,'v');

%% Start experiment
tfinal = 16;
Kp     = Kp_id;
Ki     = 0;
Kd     = 0;
open_system('pos_pid_mbd_sl')
open_system('pos_pid_mbd_sl/Scope')
sim('pos_pid_mbd_sl')

%% Save Parameters
save model_data K T numpd denpd

%% EOF of pos_id_verify.m