(define (domain rblocks)
    (:requirements :strips :equality)
    (:constants table)
    (:constants gripper)
    (:constants rl)
    (:constants rr)
    (:predicates (on ?x ?y ?r)(handemp)(holding ?x)(room ?r))
    (:action pick_up
        (:parameters (?obj ?f ?r))
        (:precondition (and(on ?obj ?f ?r)(handemp)(clear ?obj)(room ?r)))
        (:effect (and (not (handemp))(holding ?obj)(when (not(=?f table))(clear ?f)(not (on ?obj ?f ?r))(not (room ?r))))
    )
    (:action put_down
        (:parameters (?obj ?t ?r))
        (:precondition (and (holding ?obj)(room ?r)(clear ?t))
        (:effect (and (not (holding ?obj))(clear ?obj)(on ?t ?f ?r)(when (not (=?t table))(not (clear ?t))(not room ?r)))
    )
    (:action move
        (:parameters (?fr ?tr))
        (:precondition (room ?fr))
        (:effect (and(room ?tr)(not (room ?tr)))
    )
    
)