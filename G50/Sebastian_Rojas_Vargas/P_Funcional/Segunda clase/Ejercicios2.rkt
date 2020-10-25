;;EJERCICIOS PARA CLASE SCHEME
;;<><><><><><><><><><><><><><>

;; 1) Realizar ejercicio para rotar una lista de elementos n posiciones a la izquierda o la derecha según
;; sea dicha posición negativa o positiva. 
(define (rotar cant L)
  (cond ((equal? cant 0)
         L)
        ((< cant 0)
         (rotar_aux (abs cant) L))
        (else
         (reverse (rotar_aux cant (reverse L))))
        )
  )

(define (rotar_aux cant L)
  (cond ((equal? cant 0)
         L)
        (else
         (rotar_aux (- cant 1) (append (cdr L) (list (car L)))))
        )
  )

;; 7) Construya una función que se llame (general-sec A B). Esta función genera una secuencia de números en
;; una lista de A hasta B, donde  a y B son números enteros. Por ejemplo:
;; > (generar-sec 0 5)
;; (0 1 2 3 4 5)

(define (generar-sec a b)
  (cond ((equal? b -1)
         '())
        (else
         (cons a (generar-sec (+ a 1) (- b 1)))
         )
        )
  )
  
;; 2) Realizar una función que obtenga el n-esimo elemento de una lista pero utilizando solamente map
;; (sin recursión). Tip: Utilizar lista de índices.

(define (problema2 n lista indices)
  (cond ((equal? n (car indices))
         (car lista)
         else (
               (problema2 n (cdr lista) (cdr indices))
               ))
        )
  )

(define (problema2_2 n lista indices)
  (map (lamba (a b)
              (
               )
              ) lista indices
       )
  )

;; 3) Construya una función que se llame sub-conjunto? Esta función recibe dos argumentos y debe producir
;; un valor #t cuando el primer argumento es subconjunto del segundo y #f en caso contrario
(define (sub-conjunto? c1 c2)
  (cond ((equal? (car c1) (car c2)))(
                                     (delay "si")
                                     )
        )
  )



