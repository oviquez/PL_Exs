;; 4) Construya una función que se llame (doblar E L). Esta función debe duplicar cualquier parición del
;; elemento E en la lista L. Por ejemplo:
;; > (doblar ‘a ‘(b c d a e f a))
;; (b c d a a e f a a)
;; > (duplicar ‘es ‘(hoy es jueves))
;; (hoy es es jueves)
(define (doblar E L)
  (cond ((null? L) '())
        ((equal? E (car L))
         (cons E (cons E (doblar E (cdr L))))
         )
        (else
         (cons (car L) (doblar E (cdr L)))
         )
        )
  )

;; usando map
(define (doblar2 E L)
  (apply append
         (map (lambda (x)
                (cond
                  ((equal? x E)
                   (list E E)
                   )
                  (else
                   (list x)
                   )
                  )
                ) L)
         )
  )
