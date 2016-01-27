function ex_residue

clear all;
close all;

drawResponse(1);
drawResponse(2);
drawResponse(3);

    function drawResponse(number)
        aa=[-11 -2 0];
        c = [1 0];
        x0 = [1 0]';
        
        A = [
            0 1
            -10 aa(number)
            ];
        b = [0 1]';
        d = 0;
        t = 0:0.1:5;
        sys = ss(A,b,c,d);
        
        subplot(3,3,number);
        initial(sys,x0,t);
        
        subplot(3,3,3+number);
        step(sys,t);

        subplot(3,3,6+number);               
        u = zeros(size(t))+1;
        lsim(sys,u,t,x0);       
    end


% num11 = [1 11];
% num12 = 1;
% num21 = -10;
% num22= [1 0];
%
% den = conv([1 10],[1 1]);
%
% Q=[tf(num11,den) tf(num12,den)
%    tf(num21,den) tf(num22,den) ];
%
% [k11,p]=residue(num11,den);
% [k12,p]=residue(num11,den);
% [k21,p]=residue(num11,den);
% [k22,p]=residue(num11,den);
%
% K1= [
%     k11(1) k12(1)
%     k21(1) k22(1)
%     ];
%
% K2= [
%     k11(2) k12(2)
%     k21(2) k22(2)
%     ];
%
% Q
% K1
% K2
% p
% c*Q*x0
% opt = stepDataOptions('StepAmplitude',0);
% step(c*Q*x0,opt);



end