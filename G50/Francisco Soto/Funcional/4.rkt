(define (doblar elemento lista)
  (apply append
         (map
          (lambda (x)
            (cond ((equal? x elemento) (list x x))
                  (else (list x)))
            )
          lista
          )
         )
  )

(doblar 'a '(b c d a e f a))
(doblar 'es '(hoy es jueves))
