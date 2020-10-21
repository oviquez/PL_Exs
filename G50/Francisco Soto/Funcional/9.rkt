;; 3) Construya una función que se llame sub-conjunto? Esta función recibe dos argumentos y debe producir un valor #t cuando el primer argumento es subconjunto del segundo y #f en caso contrario

(define (sub-conjunto lista1 lista2)
  (cond ((equal? lista1 ())
         #t
         )
        (else
         (andmap (lambda (x)
                   (ormap (lambda (y)
                            (equal? x y)
                            )
                          lista2)
                   )
                 lista1)
         )
        )
  )

(sub-conjunto '() '(a b c d e f))
(sub-conjunto '(a b c) '(a b c d e f))
(sub-conjunto '(a b x) '(a b c d e f))