;; 1. Escriba una función recursiva que reciba una palabra y devuelva true o false en el caso de que esta
;; sea o no un isograma. Nótese para este y para los demás ejercicios que debe recibirse una cadena string
;; (constante entre comillas) por lo que deben utilizarse funciones de Racket para convertir de cadenas a
;; listas de caracteres y normalizarlos todos o a minúscula o a mayúscula.

(define (isogramLen s x)
  (cond ((equal? s "")
         0)
        ((equal? (string-ref x 0) (string-ref s 0))
         (+ 1 (isogramLen (substring s 1) x))
         )
        (else
         (+ 0 (isogramLen (substring s 1) x) )
         )
    )
  )

(define (isogramWithoutX s x)
  (cond ((equal? s "")
         ""
         )
        ((equal? (string-ref x 0) (string-ref s 0))
         (isogramWithoutX (substring s 1) x)
         )
        (else
         (string-append (make-string 1 (string-ref s 0)) (isogramWithoutX (substring s 1) x))
         )
    )
 )
(define (isogram? s)
  (cond ((equal? s "")
         #t)
        ((equal? (string-length s) 1)
         #t)
        ((equal? (isogramLen s (make-string 1 (string-ref s 0))) (isogramLen s (make-string 1 (string-ref s 1))) )
         (isogram? (isogramWithoutX s (make-string 1 (string-ref s 0)))
          )
         )
        (else
         #f
         )
    )
 )