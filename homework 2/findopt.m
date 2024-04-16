function [ind,dis] = findopt(pop,totaldis)
[x,y]=size(pop);
ind=pop(1,:);
dis=totaldis(1);
for j=2:x
    if totaldis(j)<=dis
        ind=pop(j,:);
        dis=totaldis(j);
    end
end
end

