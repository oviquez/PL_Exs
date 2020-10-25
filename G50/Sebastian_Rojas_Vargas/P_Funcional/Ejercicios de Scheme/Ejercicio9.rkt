;; 9) Construya una función que se llame sub-conjunto? Esta función recibe dos argumentos y debe producir
;; un valor #t cuando el primer argumento es subconjunto del segundo y #f en caso contrario. Por ejemplo: 
;; > (sub-conjunto? '() '(a b c d e f))
;; #t
;; > (sub-conjunto? '(a b c) '(a b c d e f))
;; #t
;; > (sub-conjunto? '(a b x) '(a b c d e f))
;; #f

(define (sub-conjunto? L1 L2)
  (cond ((null? L1)
         #t
         )
        ((null? L2)
         #f)
        ((equal? (car L1) (car L2))
         (sub-conjunto? (cdr L1) L2)
         )
        (else
         (sub-conjunto? L1 (cdr L2))
         )
        )
  )