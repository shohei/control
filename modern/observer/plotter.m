close all;

subplot(4,1,1)
hold on;
plot(t,x(:,1))
plot(t,x_hat(:,1))

subplot(4,1,2)
hold on;
plot(t,x(:,2))
plot(t,x_hat(:,2))

subplot(4,1,3)
hold on;
plot(t,x(:,3))
plot(t,x_hat(:,3))

subplot(4,1,4)
hold on;
plot(t,x(:,4))
plot(t,x_hat(:,4))

