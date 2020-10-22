;; 10) Realice la función (aplanar L). Esta función recibe una lista con múltiples listas anidadas como
;; elementos y devuelve una lista con los mismos elementos de manera lineal (sin listas). Puede implementar
;; además una versión del ejercicio usando map Ej: 
;; > (aplanar '(1 2 (3 (4 5) (6 7))))
;; (1 2 3 4 5 6 7)
(define (aplanar L)
  (cond ((null? L)
         '())
        ((list? (car L))
         (append (aplanar (car L)) (aplanar (cdr L)))
         )
        (else
         (cons (car L) (aplanar (cdr L)))
         )
        )
  )

;; usando map (usar apply append)
(define (aplanar2 L)
  (map (lambda (x)
         (cond ((list? (car x))
                
                )
           )
        ) L
       )
  )