;; 2) Escriba un programa que determine la suma de los dígitos de un número entero positivo N mayor que 0.
;; Sugerencia: utilizar las funciones de quotient y remainder. A continuación se presentan algunos ejemplos:
;; > (sumd 124)
;; 7
;; > (sum 12480)
;; 15
(define (sumd N)
  (cond ((equal? N 0)
         0
         )(else
           (+ (remainder N 10) (ejercicio2 (quotient N 10)))
           )
          )
  )
