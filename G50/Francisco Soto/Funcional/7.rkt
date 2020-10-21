(define (generar-sec a b)
  (cond((equal? a b) (list a))
       (else
        (append (list a) (generar-sec (+ a 1) b))
        )
       )
  )

(generar-sec 0 5)