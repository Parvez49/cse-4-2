(define (problem case)
    (:domain blocks)
    (:objects A B C D E F)
    (:init 
        (clear A)(clear F)(clear D)(clear C)(on A B rl)(on B table rl)(on C table rl)(on d table rr)(on E table rr)(on F E rr)
    )
    (:goal 
        (clear D)(on D E rl)(on E F rl)(on F table rl)(on A B rr)(on B C rr)(on C table rr)
    )
)