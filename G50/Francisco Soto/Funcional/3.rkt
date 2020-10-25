(define (duplicar elemento lista)
  (cond ((equal? lista ())
         #f)
        (else
         (map (lambda (x) elemento)
              lista
              )
         )
        )
  )

(duplicar 'a '(1 3 4))
(duplicar 'a '())