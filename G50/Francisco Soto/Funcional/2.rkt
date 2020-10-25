(define (sumaDigitos numero)
  (cond ((< numero 10) numero)
        (else
         (+ (remainder numero 10) (sumaDigitos (quotient numero 10)))
         )
        )
  )

(sumaDigitos 124)
(sumaDigitos 12480)