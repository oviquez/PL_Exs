(define (merge lista1 lista2)
  (cond ((null? lista1) lista2)
        ((null? lista2) lista1)
        (else
         (cond ((<= (car lista1) (car lista2))
                   (append (list (car lista1)) (merge (cdr lista1) lista2))
                   )
               (else
                (append (list (car lista2)) (merge lista1 (cdr lista2)))
                )
               )
         )
        )
  )

(merge '(1 2 3 4) '(5 6 7 8))
(merge '(1 2 3) '(1 2 3 4))