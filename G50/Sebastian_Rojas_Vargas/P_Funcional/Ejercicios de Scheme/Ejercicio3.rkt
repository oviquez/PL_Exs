;; 3) Construya una función que se llame (duplicar E L). Esta función debe sustituir cada uno de los elementos
;; de la lista L por el elemento E. A continuación algunos ejemplos.
;; > (duplicar ‘a ‘(1 3 4))
;; (a a a)
;; > (duplicar ‘a ‘())
;; #f
(define (duplicar E L)
  (cond ((null? L)
         '()
         )(else
           (cons E (duplicar E (cdr L)))
           )
   )
 )

;; usando map
(define (duplicar2 E L)
  (map (lambda (x)
         E
         ) L
   )
  )