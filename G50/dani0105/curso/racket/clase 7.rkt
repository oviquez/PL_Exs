(define (sub-conjunto list1 list2)
  (andmap equal? list1 list2)
)

(define (general-sec a b)
  (cond ((equal? a b)
         (list a))
        (else
         (append (list a) (general-sec (+ a 1) b)))
        ))

(define (getValueInIndex index lista)
  (car (apply append (map (lambda (a b)
         (cond ((equal? a index)
               (list b))
               (else
                 '()
                 ))) (general-sec 1 (length lista)) lista)))
  )


