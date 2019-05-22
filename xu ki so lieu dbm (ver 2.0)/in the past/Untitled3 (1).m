m = 100;
n = 60;
p = 20;
q = 50;
r = 65;
s = 44;
t = 1; 

x = 1:1:m;
y = 1:1:n;
[xx yy] = meshgrid(x, y);
z = zeros(60,100);

for i = 1:n
        for j = 1:m
            if((xx(i, j) == p  && yy(i, j) <= q) || (yy(i, j) == q && xx(i, j) >= p))
                z(i, j) = 40
                t = t+1;
            end
        end
end

linespace3(z);
xlabel('x');
ylabel('y');
zlabel('z');
    
