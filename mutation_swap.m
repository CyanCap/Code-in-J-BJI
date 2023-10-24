function [newpop] = mutation_swap(pop,mpro)
[x,y]=size(pop);
newpop=pop;
for i=1:1:x
    if(rand<mpro)
        xpoint=sort(randperm(y,2));
        s=xpoint(1);t=xpoint(2);        %Í»±äÎ»ÖÃ
        temp=newpop(i,s);
        newpop(i,s)=newpop(i,t);
        newpop(i,t)=temp;
    end
end
end

