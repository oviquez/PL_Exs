;; 7) Construya una función que se llame (general-sec A B). Esta función genera una secuencia de números en
;; una lista de A hasta B, donde  a y B son números enteros. Por ejemplo:
;; > (generar-sec 0 5)
;; (0 1 2 3 4 5)
(define (generar-sec A B)
  (cond ((equal? A B)
         (list B)
         )
        (else
         (cons A (generar-sec (+ A 1) B)
               )
         )
        )
  )

;; usando map (incompleto)
(define (generar-sec2 A B)
  (lambda (x)
    (cond
      ((equal? x B)
       B)
      (else
       (+ x 1)
       )
      )
    ) A
  )


