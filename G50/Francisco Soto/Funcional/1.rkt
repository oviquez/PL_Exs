(define (calcMontoCapital capital interes anios)
  (cond ((equal? anios 0)
         capital
         )
        (else
         (calcMontoCapital (+ capital (* capital interes)) interes (- anios 1))
         )
   )
  )

(calcMontoCapital 2000 0.10 0)
(calcMontoCapital 2000 0.10 1)
(calcMontoCapital 2000 0.10 2)
(calcMontoCapital 2000 0.10 3)