;; 1) Se tiene una cuenta de ahorros en la cual se deposita un capital C al inicio de un periodo de un año.
;; Por cada año que transcurra se recibe un interés I sobre el capital depositado. Es decir al terminar el
;; año se cuenta con el capital inicial más interés ganado. Construya una función (int Cap, I, N) que calcula
;; el monto que se recibe al depositar un capital a un interés dado durante un cierto número de años. Debe
;; producir los resultados de acuerdo con el siguiente cuadro:
;; 2000*(1+0.1)**1
;; >2200
;; C * (1+I)**N
(define (ejercicio1 cap I N)
  (cond ((equal? N 0)
         cap
         )(else(
                * (+ 1 I) (ejercicio1 cap I (- N 1))
                )
               )
          )
  )
  

  