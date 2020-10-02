fun divide(x,y) =   
    if x = 0 then (0,0) else
        let
          val (q,r) = divide(x div 2 ,y);
          val q1 = 2*q;
          val r1 = 2*r
        in
            if x mod 2 = 1 then 
                let
                val r2 = r1+1
                in
                if (r2<y) then (q1,r2) else (q1+1,r2-y)

                end
            else if (r1<y) then (q1,r1) else (q1+1,r1-y)
        end;