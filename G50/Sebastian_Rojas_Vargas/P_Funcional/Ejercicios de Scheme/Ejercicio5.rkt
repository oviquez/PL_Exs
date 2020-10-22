;; 5) Construya una función que se llame (primeros L). Esta función recibe en L una lista de listas y debe
;; devolver una lista con el primer elemento de cada una de ellas. Por ejemplo:
;; > (primeros ‘((1 2 3)(1 2 3)))
;; (1 1)
;; > (primeros ‘((a b c)(d e f)(g h i)))
;; (a d g)
(define (primeros L)
  (cond ((null? L)
         '()
         )(else
           (cons (car (car L)) (primeros (cdr L)))
                )
          )
  )

;; usando map
(define (primeros2 L)
  (map
   (lambda (x)
     (car x)
     ) L
    )
  )
