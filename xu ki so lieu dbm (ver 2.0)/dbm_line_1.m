z1 = zeros(n,m);
z2 = zeros(n,m);
z3 = zeros(n,m);
g = length(line1)/60;

dbm1=zeros(60,3);
for j = 1:3
    e=1;
    for i = 1:60
        for k = e:int16(g*i)
            
            dbm1(i,j) = dbm1(i,j)+line1(k,j); 
        end
        
        dbm1(i,j) = dbm1(i,j)/(int16(g*i)-e+1);
        e = int16(g*i)+1;
        
% % % %         old scale choice
%         if line1(3*i, j)== -1;
%             dbm1(i,j) = (line1(3*i-1,j)+line1(3*i-2,j))/2;
%         else
%             dbm1(i,j) = (line1(3*i-1,j)+line1(3*i-2,j)+line1(3*i,j))/3 ;
%         end
    end
end
j=60;
s=0;
while j >= 1
    s=s+1;
    
    z1(20, j+7)= dbm1(s, 1);
    z2(20, j+7)= dbm1(s, 2);
    z3(20, j+7)= dbm1(s, 3);
 
    j = j-1;
end

