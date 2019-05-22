t1 = zeros(n,m);
t2 = zeros(n,m);
t3 = zeros(n,m);
g = length(line2)/78;

dbm2 = zeros(78,3);
for j = 1:3
    e=1;
    for i = 1:78
         for k = e:int16(g*i)

            dbm2(i,j) = dbm2(i,j)+line2(k,j); 
         end

         dbm2(i,j) = dbm2(i,j)/(int16(g*i)-e+1);
         e = int16(g*i)+1;
        
        
% % % % old scale choice
%         if line2(3*i-1, j)== -1;
%             dbm2(i,j) = line2(3*i-2,j);
%         else
%             dbm2(i,j) = (line2(3*i-1,j)+line2(3*i-2,j)+line2(3*i,j))/3 ;
%         end
    end
end



for i = 1:78
    t1( i+20, 20)=dbm2(i, 1);
    t2( i+20, 20)=dbm2(i, 2);
    t3( i+20, 20)=dbm2(i, 3);
              
end