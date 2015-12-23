clear all;
close all;
ts=1/30;
K = 1.904071;
T = 0.166667;
u_offset=1.5;
% u_offset = 1.258763;
% K=1.57;
% T=0.76;
% u_offset=1.03;
open_system('velo_verify');
open_system('velo_verify/Scope');
simset('SrcWorkspace','current');
set_param('velo_verify','SimulationCommand','start');

while(1)
    stat=get_param('velo_verify','SimulationStatus');
    if(strcmp(stat,'stopped'))
        break;
    end
    pause(3);
end

save modeldata K T u_offset;


