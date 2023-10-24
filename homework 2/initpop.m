function pop = initpop(dis,n)
[x,y]=size(dis);
pop=zeros(n,y);
for i=1:n
    pop(i,:)=randperm(y,y);
end
end

