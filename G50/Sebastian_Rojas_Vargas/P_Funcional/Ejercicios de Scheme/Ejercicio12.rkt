;; 12) Utilice la función map para definir la función eliminar_elemento que recibe un elemento E y una lista
;; L y retorna la lista L sin el elemento E. Si el elemento no existe, retorna la lista L original.
;; > (eliminar_elemento 3 ‘(1 2 3 4 5))
;; (1 2 4 5)
;; > (eliminar_elemento 0 ‘(1 2 3 4 5))
;; (1 2 3 4 5)

(define (eliminar_elemento E L)
  (apply append (map
   (lambda (x)
     (cond
       ((equal? E x)
        '()
        )(else
          (list x)
          )
       )
     ) L
   )
   )
 )