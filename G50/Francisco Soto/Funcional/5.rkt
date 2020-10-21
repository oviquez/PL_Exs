(define (primeros lista)
  (map (lambda (x) (car x))
       lista)
  )

(primeros '((1 2 3)(1 2 3)))
(primeros '((a b c)(d e f)(g h i)))

(define (segundos lista)
  (map (lambda (x) (car (cdr x)))
       lista)
  )

(segundos '((1 2 3)(1 2 3)))
(segundos '((a b c)(d e f)(g h i)))