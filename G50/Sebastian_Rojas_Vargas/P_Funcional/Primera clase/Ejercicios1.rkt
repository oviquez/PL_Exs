;; Hacer un ejercicio que sume los elementos desde 0 hasta un numero N determinado

(define (sumarHastaN n)
  (if (= n 0)
      0
      (+ n (sumarHastaN (- n 1)
                        )
         )
      )
  )

;; 2) Modificar el ejercicio anterior para que sume desde un inicio A hasta un final B.
;; Por ejemplo desde 5 hasta 9. Deve verificar que A sea menor o igual que B.
(define (sumarHastaN2 A B)
  (cond ((= B A)
         A)
        (else
         (+ B (sumarHastaN2 A (- B 1))))
        )
  )