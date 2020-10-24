(define (diagonal n matrix)
  (let* ([index 0])
    (map ; Recorro Cada linea
     (lambda (row)
       (map
         (lambda (element) ; Recorro Cada elemento
           (let* ([aux 0])
             (cond((equal? index aux) ; Esta el auxiliar en el indice ?
                 (+ element 0)
              (else ( (+ aux 1)(set! element 0)))  ; Volver en 0 el elemento                  
          )))
         row))
     matrix)) ; Al final debería devolver ( (1 0 0) ( 0 2 0) (0 0 8))
))





(define ( resolver-automata cadena automata estado)(
  getValueInIndex (doAutomata cadena automata 0) estado
))

(define ( doAutomata cadena automata estado )
   (cond ((null? cadena)
        estado)
   (else (
     cond ((zero? (car cadena))
           (doAutomata (cdr  cadena) automata (car (getValueInIndex estado automata))))
   (else(doAutomata (cdr  cadena) automata ( lastElement (getValueInIndex estado automata))) )) ))
)


(define (getValueInIndex index lista)
  (cond ((zero? index) ( car lista))
  (else ( getValueInIndex (- index 1) (cdr lista)) )                                    
))

(define (lastElement l)
  (cond ((null? (cdr l)) (car l))
        (else (lastElement (cdr l)))))
