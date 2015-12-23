%% psd_test.m

a = arduino('COM3');
a.analogReference('default')
N = 500;
v_hist = zeros(N,1);
for i=1:N
    v_hist(i) = a.analogRead(2)*(5/1023);
    fprintf('Voltage = %f\n',v_hist(i));
end
delete(a);

figure(1)
v_ave = mean(v_hist);
t     = 1:N;
plot(t,v_hist,t,ones(N,1)*v_ave);
xlabel('Step'), ylabel('Voltage')
legend('Measured','Average')
axis([0 N 0 5])
fprintf('Average = %f\n',v_ave);

%% EOF of psd_test.m