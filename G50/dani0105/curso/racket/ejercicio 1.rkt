(define (printMoney money interest year result)
  (display money)
  (display " , ")
  (display interest)
  (display " , ")
  (display year)
  (display " , ")
  (display result)
  (newline))

(define (calculateResult money interest year yearTarget)
  (cond (
     (equal? year yearTarget)
        (printMoney money interest year (+ (* money interest) money))
     )(else
        (printMoney money interest year (+ (* money interest) money))
        (calculateResult (+ (* money interest) money) interest (+ year 1) yearTarget)
        
     )
 )
)

(define (calculate money interest year)
  (display "Capital  Interes  Años  Resultado")
  (newline)
  (cond (
     (zero? year)
       (printMoney money interest 0 (+ (* money interest) money))
     )(else
        (printMoney money interest 0 money)
        (calculateResult money interest 1 year)
     )
 )
)