Q:={a 1 ,a 2 };
{ początkowo, dla dowolnego i, j: v[i,j]=0, oraz v’[i,j]=0 }
v[a 1 ,a 2 ]:=1;
t:=0;
while not Q.pusta do begin
    Q2 :=pusta kolejka;
    {ruch pierwszego agenta}
    while not Q.pusta do begin
        (u,v):=Q.PobierzElement;
        if (u=v) then
            “Znaleziono rozwiązanie — t”
            STOP;
        for i∈ {k : (u, k) jest krawędzią w G} do
            if v’[i,v]=0 then begin
                v’[i,v]:=1;
                Q2 .Dodaj(i,v)
            end
        end;
        {ruch drugiego agenta}
    while not Q2 .pusta do begin
        (u,v):=Q2 .PobierzElement;
        for i∈ {k : (v, k) jest krawędzią w G} do
            if v[u,i]=0 then begin
                v[u,i]:=1;
                Q.Dodaj(i,v)
            end
        end;
    t++;
end;
“Brak rozwiązania”